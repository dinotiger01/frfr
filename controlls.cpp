//
// Created by FFlyingFish on 8/2/26.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "controlls.h"
#include <QString>
#include <QQuickItem>
#include <QQuickWindow>
#include <QImage>
#include <QRect>
#include <QDebug>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <vector>
#include <string>
using json = nlohmann::json;

using namespace std::chrono_literals;
using namespace std;

namespace MTG_size_editer {
    float multX = 1;
    float multY = 1;
    float multC = 1;
    vector<vector<int>> card_pos;
    vector<string> card_pic;
    std::vector<std::pair<int, string>> cards;
    unordered_map<string, string> card_map;
    vector<string> miss;
    vector<pair<pair<vector<int>, string>,string>> ex;


    void controlls::exporter(int dex) {
        int count = cards[dex].first;
        string name = cards[dex].second;
        for (int i =0; i < count; i++) {
            pair<vector<int>, string> temp_pair;
            vector<int> temp_vec;
            string tring;


        }
    }

    void controlls::stringToVec(QString s) {
        // std::cout << s.toStdString() << "\n";
        std::string ss = s.toStdString();

        std::pair<int, string> temp;
        temp.first = 0;
        temp.second = "";
        std::string tring;
        bool numAss = true;

        for (int i = 0; i< ss.length(); i++) {
            if (numAss) {
                if (ss[i] == ' ') {
                    try {
                        temp.first = stoi(tring);
                    }
                    catch (exception &e) {
                        cout << e.what();
                    }
                    tring = "";
                    numAss = false;
                    continue;
                }
                tring += ss[i];
            }else {
                if (ss[i] == '\n') {
                    temp.second = tring;
                    cards.push_back(temp);
                    temp.first = 0;
                    temp.second = "";
                    tring = "";
                    numAss = true;
                    continue;
                }
                tring += ss[i];
            }
        }
        temp.second = tring;
        // std::cout<< s.toStdString() << "\n\n\n";
        for (auto i : cards) {
            std::cout << std::to_string(i.first) << " : " << i.second << "\n";
        }
    }

    QString controlls::getImgByDex(int ig) {
        vector<int> temp = {1,1,1,1};
        card_pos.push_back(temp);

        string t = "";
        card_pic.push_back(t);

        auto it = card_map.find(cards[ig].second);

        if (it == card_map.end()) {
            cout << "Not found: " << cards[ig].second << endl;
            return "";
        }

        return QString::fromStdString(it->second);
    }

    void controlls::skip(int i) {
        cards[i].first = 0;
        miss.push_back(cards[i].second);

        auto carg = card_map.find(cards[i].second);
        carg->second = "";
    }

    float controlls::getMultX() {
        return multX * multC;
    }
    float controlls::getMultY() {
        return multY * multC;
    }
    void controlls::setMultX(float dif) {
        multX = dif;
    }
    void controlls::setMultY(float dif) {
        multY = dif;
    }
    void controlls::setMultC(float difX, float difY) {
        if (difX < difY) {
            multC = difX;
        }
        else {
            multC = difY;
        }

    }

    int controlls::getDex() {
        return cards.size();
    }

    bool controlls::logg(QObject *gooper, int name) {
        if (!gooper) {
            qWarning() << "Error: Object is null!";
            return false;
        }
        QQuickItem* item = qobject_cast<QQuickItem*>(gooper);
        if (!item) {
            qWarning() << "Error: This object is a" << gooper->metaObject()->className()
                       << "and is not a visual QML item.";
            return false;
        }
        QQuickWindow* window = item->window();
        if (!window) {
            qWarning() << "Error: The visual item has not been drawn to a window yet.";
            return false;
        }
        QImage windowImage = window->grabWindow();
        if (windowImage.isNull()) {
            return false;
        }
        QRectF sceneRect = item->mapRectToScene(item->boundingRect());
        qreal dpr = window-> devicePixelRatio();
        QRect cropTarget(
           static_cast<int>(sceneRect.x() * dpr),
           static_cast<int>(sceneRect.y() * dpr),
           static_cast<int>(sceneRect.width() * dpr),
           static_cast<int>(sceneRect.height() * dpr)
       );
        QImage finalImage = windowImage.copy(cropTarget);

        return finalImage.save("../output/my_capture.png", "PNG");
    }

    void controlls::logger(QString s) {
        cout << s.toStdString();
    }

    QString controlls::getPic(int dex) {
        return QString::fromStdString(card_pic[dex]);
    }
    int controlls::getPos(int dex, int wit) {
        return card_pos[dex][wit];
    }

    void controlls::save(int x, int y, int wid,int hei,int dex, QString pic){
        card_pos[dex] = {x,y,wid,hei};
        card_pic[dex] = pic.toStdString();
    }

    size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
        userp->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
    vector<string> parCSV(const string& l) {
        vector<string> res;
        string field = "";
        bool quote = false;

        for (size_t i = 0; i < l.length(); ++i) {
            char c = l[i];

            if (c == '"') {
                if (quote && i + 1 < l.length() && l[i+1] == '"') {
                    field += '"';
                    i++;
                }else {
                    quote = !quote;
                }
            }else if (c == ',' && !quote) {
                res.push_back(field);
                field = "";
            }else {
                field += c;
            }
        }
        res.push_back(field);
        return res;
    }

    void controlls::setCard() {
        // get the file
        string tt;
        ifstream filer("../scryfall-card-image-urls.csv");

        if (!filer.is_open()) {
            cout << "asjdl;jas;dj";
        }


        if (getline(filer, tt)) {
            // Header skipped
        }



        while (getline (filer, tt)) {
            // Output text
            cout << tt;

            // stringstream ss(tt);
            // string field;
            vector<string> row = parCSV(tt);

            if (row.size() >= 6) {
                string name = row[0];
                string imgurl = row[5];

                card_map[name] = imgurl;
            }
        }

        for (auto i: card_map) {
            cout << i.first << " : " << i.second << endl;
        }
        filer.close();

    }

    /*[COMMANDER]
1 Muerra, Trash Tactician
1 Celestial Reunion
1 Sol Ring
1 Vandalblast
1 Bakersbane Duo
1 Bark-Knuckle Boxer
1 Brazen Collector
1 Goblin Anarchomancer
1 Heroic Intervention
1 Hoarder's Overflow
1 Keen-Eyed Curator
1 Lightning Greaves
1 Masked Vandal
1 Metallic Mimic
1 Peerless Recycling
1 Raccoon Rallier
1 Steely Resolve
1 Take Out the Trash
1 Trailtracker Scout
1 Wandertale Mentor
1 Adaptive Automaton
1 Barkform Harvester
1 Beast Within
1 Bloodline Pretender
1 Brambleguard Veteran
1 Byway Barterer
1 Chomping Changeling
1 Coati Scavenger
1 For the Ancestors
1 Herald's Horn
1 Patchwork Banner
1 Prosperous Bandit
1 Realmwalker
1 Roughshod Duo
1 Scrapshooter
1 Sylvan Scavenging
1 Taurean Mauler
1 Valley Flamecaller
1 Big Score
1 Chameleon Colossus
1 Decimate
1 Gathering Stone
1 Maskwood Nexus
1 Molten Echoes
1 Roaming Throne
1 Roar of the Crowd
1 Rust-Shield Rampager
1 Scrappy Bruiser
1 Teapot Slinger
1 Banner of Kinship
1 Collective Inferno
1 Escape to the Wilds
1 Junkblade Bruiser
1 Return of the Wildspeaker
1 Vanquisher's Banner
1 Argivian Avenger
1 Blasphemous Act
1 Cavern of Souls
1 Cinder Glade
1 Command Tower
1 Copperline Gorge
15 Forest
1 Game Trail
1 Kessig Wolf Run
15 Mountain
1 Oakhollow Village
1 Path of Ancestry
1 Rockface Village
1 Rockfall Vale
1 Rootbound Crag
1 Stomping Ground
1 Three Tree City

*/
}