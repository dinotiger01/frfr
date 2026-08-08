import QtQuick
import QtQuick.Controls
import QtQuick.Window
import Qt5Compat.GraphicalEffects
import MainApplication

Window {
    width: 5 * 160
    height: 7 * 160
    visible: true
    title: "MTG_APP"
    Item{
        id: tab
        anchors.fill: parent
        Item{
            id: varia
        }
        Controlls{
            id: imgScaler
        }
        Row{
            TextArea{
                id: texter
            }
            Button{
                id: uha
                text: "find"
                onClicked:{
                    // car.source = "https://gatherer-static.wizards.com/Cards/medium/"+texter.text+".webp"

                    imgScaler.setCard();
                    imgScaler.stringToVec(texter.text)
                    // roww.model = imgScaler.getDex()
                    texter.text = ""
                    // car.source = imgScaler.lookForCard(texter.text)
                }
            }
            Button{
                text: "load"
                onClicked:{
                    // car.source = "https://gatherer-static.wizards.com/Cards/medium/"+texter.text+".webp"

                    // uha.text = imgScaler.lookForCard("Caustic Bronco");
                    roww.model = imgScaler.getDex()
                    // car.source = imgScaler.lookForCard(texter.text)
                }
            }
            Rectangle{
                width : 300
                height: 100
                color: "green"
                Text{
                    text: "drop area"
                    font.pointSize: 45
                    // Text.AlignHCenter: parent.horizontalCenter
                }
                DropArea{
                    width: parent.width
                    height: parent.height
                    onDropped: drop =>{
                        imgScaler.logger(drop.urls)
                        dragAble.source = drop.urls.toString()
                    }
                }
            }
        }
        DropArea{
            id: boya
            width: 100
            height: 100

            // onDropped: function(drop){
            //     if(drop.hasUrls){
            //         for(let i = 0; i < dropUrl.length; i++)
            //         car.source += drop.urls[i];
            //     }
            // }
        }
        Image{
            id: car
            width: 5 * 160 / 1.5
            height: 7 * 160 / 1.5
            source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

            //5* 160 - (5*160/1.5)
            //7*160 -(7*160/1.5)
            x: 133.5
            y: 186.6
            Item{
                id: stuff
                width: 452
                height: 331.5
                x: 40
                y: 83
                clip: true
                Image{
                    id: dragAble
                    source: "cat.jpg"
                    width: sourceSize.width
                    height: sourceSize.height
                    Drag.active: dragArea.drag.active
                    Drag.hotSpot.x: 10
                    Drag.hotSpot.y: 10
                    MouseArea{
                        id: dragArea
                        anchors.fill: parent

                        drag.target:dragAble
                        onReleased:{

                            // dragAble.source = "kitty.jpg"
                            cI.y = stuff.y + car.y + dragAble.height + dragAble.y
                            cI.x = stuff.x + car.x +dragAble.width + dragAble.x
                        }
                    }
                }
            }
        }
        Rectangle{
            id: cI
            width: 10
            height: 10
            x: stuff.x + car.x + dragAble.sourceSize.width
            y: stuff.y + car.y + dragAble.sourceSize.height
            color: "blue"
            Drag.active: dragAreaC.drag.active
            Drag.hotSpot.x : 10
            Drag.hotSpot.y : 10
            MouseArea{
                id: dragAreaC
                anchors.fill: parent
                drag.target: parent
            }
            onXChanged:{
                imgScaler.setMultC(cI.x - (stuff.x + car.x + dragAble.x) / dragAble.sourceSize.width, (cI.y - (stuff.y + car.y + dragAble.y)) / dragAble.sourceSize.height);
                dragAble.width = dragAble.sourceSize.width * imgScaler.getMultX()
                dragAble.height = dragAble.sourceSize.height * imgScaler.getMultY()
                // rI.x = dragAble.width
                // bI.x = dragAble.width /2 - 5
            }
        }
        ScrollView{
            width: 100
            height: parent.height - 30
            y: 30
            Column{
                spacing: 10
                Repeater{
                    id: roww
                    // model: imgScale.getDex()
                    Button{
                        id: button
                        width: 100
                        height: 100
                        background: Image{
                            anchors{
                                fill: parent
                            }
                            id: imger
                            source: imgScaler.getImgByDex(index);

                        }
                        onClicked:{
                            car.source = imger.source;
                            varia.width = index;

                            dragAble.x = imgScaler.getPos(index, 0)
                            dragAble.y = imgScaler.getPos(index, 1)
                            dragAble.width = imgScaler.getPos(index, 2)
                            dragAble.height = imgScaler.getPos(index, 3)
                            dragAble.source = imgScaler.getPic(index)
                        }
                    }
                }
            }
        }
        Row{
            anchors{
                right: parent.right
                bottom: parent.bottom
            }
            Button{
                text: "export"
                onClicked:{
                    tab.visible = false
                    expor.visible = true
                }
            }
            Button{
                text: "save"
                onClicked:{
                    imgScaler.logg(car, varia.width);
                    imgScaler.save(dragAble.x,dragAble.y,dragAble.width,dragAble.height, varia.width, dragAble.source)
                }
            }
            Button{
                text: "skip"

                onClicked: {
                    imgScaler.skip(varia.width)
                    roww.itemAt(varia.width).background.source = "kitty.jpg"
                }
            }
        }
    }
    Item{
        id: expor
        visible: false
        width: 10 * 160 /1.5
        height: 14 *160/ 1.5
        Item{
            id: grig
            anchors.fill: parent
            Grid{
                anchors.fill: parent
                 columns: 3
                 rows: 3
                Image{
                    // id: car
                    width: parent.width / 3
                    height: parent.height / 3
                    source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

                    //5* 160 - (5*160/1.5)
                    //7*160 -(7*160/1.5)
                    x: 133.5 *2/3
                    y: 186.6 *2/3
                    Item{
                        // id: stuff
                        width: 452*2/3
                        height: 331.5*2/3
                        x: 40*2/3
                        y: 83*2/3
                        clip: true
                        Image{
                            // id: dragAble
                            source: "cat.jpg"
                            width: sourceSize.width*2/3
                            height: sourceSize.height*2/3
                        }
                    }
                }
                Image{
                    // id: car
                    width: parent.width / 3
                    height: parent.height / 3
                    source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

                    //5* 160 - (5*160/1.5)
                    //7*160 -(7*160/1.5)
                    x: 133.5 *2/3
                    y: 186.6 *2/3
                    Item{
                        // id: stuff
                        width: 452*2/3
                        height: 331.5*2/3
                        x: 40*2/3
                        y: 83*2/3
                        clip: true
                        Image{
                            // id: dragAble
                            source: "cat.jpg"
                            width: sourceSize.width*2/3
                            height: sourceSize.height*2/3
                        }
                    }
                }
                Image{
                    // id: car
                    width: parent.width / 3
                    height: parent.height / 3
                    source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

                    //5* 160 - (5*160/1.5)
                    //7*160 -(7*160/1.5)
                    x: 133.5 *2/3
                    y: 186.6 *2/3
                    Item{
                        // id: stuff
                        width: 452*2/3
                        height: 331.5*2/3
                        x: 40*2/3
                        y: 83*2/3
                        clip: true
                        Image{
                            // id: dragAble
                            source: "cat.jpg"
                            width: sourceSize.width*2/3
                            height: sourceSize.height*2/3
                        }
                    }
                }
                Image{
                    // id: car
                    width: parent.width / 3
                    height: parent.height / 3
                    source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

                    //5* 160 - (5*160/1.5)
                    //7*160 -(7*160/1.5)
                    x: 133.5 *2/3
                    y: 186.6 *2/3
                    Item{
                        // id: stuff
                        width: 452*2/3
                        height: 331.5*2/3
                        x: 40*2/3
                        y: 83*2/3
                        clip: true
                        Image{
                            // id: dragAble
                            source: "cat.jpg"
                            width: sourceSize.width*2/3
                            height: sourceSize.height*2/3
                        }
                    }
                }
                Image{
                    // id: car
                    width: parent.width / 3
                    height: parent.height / 3
                    source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

                    //5* 160 - (5*160/1.5)
                    //7*160 -(7*160/1.5)
                    x: 133.5 *2/3
                    y: 186.6 *2/3
                    Item{
                        // id: stuff
                        width: 452*2/3
                        height: 331.5*2/3
                        x: 40*2/3
                        y: 83*2/3
                        clip: true
                        Image{
                            // id: dragAble
                            source: "cat.jpg"
                            width: sourceSize.width*2/3
                            height: sourceSize.height*2/3
                        }
                    }
                }
                Image{
                    // id: car
                    width: parent.width / 3
                    height: parent.height / 3
                    source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

                    //5* 160 - (5*160/1.5)
                    //7*160 -(7*160/1.5)
                    x: 133.5 *2/3
                    y: 186.6 *2/3
                    Item{
                        // id: stuff
                        width: 452*2/3
                        height: 331.5*2/3
                        x: 40*2/3
                        y: 83*2/3
                        clip: true
                        Image{
                            // id: dragAble
                            source: "cat.jpg"
                            width: sourceSize.width*2/3
                            height: sourceSize.height*2/3
                        }
                    }
                }
                Image{
                    // id: car
                    width: parent.width / 3
                    height: parent.height / 3
                    source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

                    //5* 160 - (5*160/1.5)
                    //7*160 -(7*160/1.5)
                    x: 133.5 *2/3
                    y: 186.6 *2/3
                    Item{
                        // id: stuff
                        width: 452*2/3
                        height: 331.5*2/3
                        x: 40*2/3
                        y: 83*2/3
                        clip: true
                        Image{
                            // id: dragAble
                            source: "cat.jpg"
                            width: sourceSize.width*2/3
                            height: sourceSize.height*2/3
                        }
                    }
                }
                Image{
                    // id: car
                    width: parent.width / 3
                    height: parent.height / 3
                    source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

                    //5* 160 - (5*160/1.5)
                    //7*160 -(7*160/1.5)
                    x: 133.5 *2/3
                    y: 186.6 *2/3
                    Item{
                        // id: stuff
                        width: 452*2/3
                        height: 331.5*2/3
                        x: 40*2/3
                        y: 83*2/3
                        clip: true
                        Image{
                            // id: dragAble
                            source: "cat.jpg"
                            width: sourceSize.width*2/3
                            height: sourceSize.height*2/3
                        }
                    }
                }
                Image{
                    // id: car
                    width: parent.width / 3
                    height: parent.height / 3
                    source: "https://cards.scryfall.io/png/front/a/8/a8bc7912-e201-468a-b251-140205cb741c.png?1783903253"

                    //5* 160 - (5*160/1.5)
                    //7*160 -(7*160/1.5)
                    x: 133.5 *2/3
                    y: 186.6 *2/3
                    Item{
                        // id: stuff
                        width: 452*2/3
                        height: 331.5*2/3
                        x: 40*2/3
                        y: 83*2/3
                        clip: true
                        Image{
                            // id: dragAble
                            source: "cat.jpg"
                            width: sourceSize.width*2/3
                            height: sourceSize.height*2/3
                        }
                    }
                }
            }
        }
    }
}