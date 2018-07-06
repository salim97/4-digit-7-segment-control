import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

        Item
        {

            property int mm: 10
            anchors.fill: parent
            Text {
                anchors.top: parent.top
                anchors.topMargin: 50
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("4 Digit 7 Segment")
                font.pixelSize: 30
            }
            Row{

                id: mainRow
                spacing: 10
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -50
                anchors.horizontalCenter: parent.horizontalCenter

                Repeater{
                    id: repeater
                    model: 4

                    MyPicker {
                        onIndexSelected:{
                            myNetwork.setDigit(position, value);
                        }
                        position : index
                        model:
                            ListModel {

                            Component.onCompleted: {
                                append({ value: -1, text: " " })
                                for(var i = 0; i <= 9; i++){
                                    var norm = i.toString();
                                    if( i < 10 ) norm = ""+ i
                                    append({ value: i, text: norm })
                                }
                                append({ value: -1, text: " " })
                            }

                        }

                    }

                }
            }

        }

}
