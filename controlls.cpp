//
// Created by FFlyingFish on 8/2/26.
//

#include <iostream>
#include <fstream>
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
    std::vector<std::pair<int, string>> cards;


    // void controlls::update() {
    //     std::cout << "test" ;
    // }

    void controlls::stringToVec(QString s) {
        // std::cout << s.toStdString() << "\n";
        std::string ss = s.toStdString();

        std::pair<int, string> temp;
        temp.first = 0;
        temp.second = "";
        std::string tring;
        bool numAss = false;

        for (int i = 0; i< ss.length(); i++) {
            // std::cout << ss[i] << "\n";
            if (ss[i] == ' ') {
                continue;
            }
            if (ss[i] == '\n') {
                std::cout << "new line";
                if (tring.length() > 0) {
                    if (numAss) {
                        temp.second = tring;
                        cards.push_back(temp);
                        numAss = false;
                    }

                    // temp.first = 0;
                    // temp.second = "";
                    tring = "";


                }

                // empty the pair
                continue;
            }
            if (!numAss) {
                try {
                    std::string tss(1, ss[i]);
                    int num = std::stoi(tss);
                    temp.first = num;
                    numAss = true;
                    continue;

                }
                    catch(const std::exception &e) {
                    std::cout << e.what();
                }
            }
            tring += ss[i];

        }
        // std::cout<< s.toStdString() << "\n\n\n";
        for (auto i : cards) {
            std::cout << std::to_string(i.first) << " : " << i.second << "\n";
        }
    }
    QString controlls::getImgByDex(int ig) {
        return QString::fromStdString(lookForCard(cards[ig].second));
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

    bool controlls::logg(QObject *gooper) {
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

        return finalImage.save("/home/FFlyingFish/Downloads/frfr/my_capture.png", "PNG");
    }


    size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
        userp->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    std::string controlls::lookForCard(std::string epp) {
        // get the file
        // file serch for card name
        //return url



        // std::string eppy = epp;
        // // if (!epp) return "auh";
        // CURL* curl = curl_easy_init();
        // if (!curl) return "uhgh";
        //
        // char* output = curl_easy_escape(curl, eppy.c_str(), eppy.length());
        // if (!output) {
        //     curl_easy_cleanup(curl);
        //     return "gtughhh";
        // }
        //
        // std::string encodedName(output);
        // curl_free(output);
        // // std::cout << *output;
        //
        // std::string url = "https://api.scryfall.com/cards/named?exact=" + encodedName;
        // std::string readBuffer;
        // std::cout << url;
        // // return output;
        //
        // curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        // curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        //
        // struct curl_slist*  header = NULL;
        // header = curl_slist_append(header, "User-Agent: MyMTGApp/1.0");
        // header = curl_slist_append(header, "Accept: application/json");
        // curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
        //
        // CURLcode res = curl_easy_perform(curl);
        // // std::cout << res<<"\n";
        //
        // curl_slist_free_all(header);
        // curl_easy_cleanup(curl);
        //
        // if (res != CURLE_OK) {
        //     std::string errMsg = "Network Error: " + std::string(curl_easy_strerror(res));
        //     // std::cout << "CRITICAL CURL FAILURE: " << errMsg << std::endl
        //     return errMsg;
        // }
        //
        // if (readBuffer.empty()) {
        //     return "Error: Empty Server Response";
        // }
        //
        // try {
        //
        //     auto jsonData = json::parse(readBuffer);
        //
        //     if (jsonData.contains("image_uris")) {
        //         std::string idStr = jsonData["image_uris"]["png"].get<std::string>();
        //         std:cout << jsonData["image_uris"]["png"] << std::endl;
        //         return idStr;
        //     }
        //     else if (jsonData.contains("details") && jsonData["details"].is_string()) {
        //         std::string idstr = "Error: " + jsonData["details"].get<std::string>();
        //         return idstr;
        //     }
        // } catch (const::json::parse_error& e) {
        //     std::cout << "JSON Parse error: " << e.what() << "\nPayload was:\n" << readBuffer << std::endl;
        //     return "no";
        // }
        //
        // return "nocar";


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