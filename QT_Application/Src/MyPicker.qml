
import QtQuick 2.0

Rectangle {
    property alias model: pickerList.model
property int mm: 13
    signal indexSelected(int value)
    property int position: -1
    function setValue(value) {
        pickerList.setValue(value)
    }

    width: 10*mm
    height: 25*mm

    MyPickerList {
        id: pickerList

        width: parent.width
        height: parent.height

        onIndexChanged: {
            indexSelected(value)

        }
    }

    Image {
        id: upShadow

        sourceSize.height: 10*mm
        sourceSize.width: 10*mm
        source: "qrc:/images/icons/pickerShadowUp.svg"
        anchors {
            top: parent.top
        }
    }

    Image {
        id: downShadow

        sourceSize.height: 10*mm
        sourceSize.width: 10*mm
        source: "qrc:/images/icons/pickerShadowDown.svg"
        anchors {
            bottom: parent.bottom
        }
    }

    Rectangle {
        id: topSelector

        width: parent.width
        height: parseInt(0.3*mm)
        color: "#33b5e5"

        anchors {
            top: parent.top
            topMargin: pickerList.itemHeight
        }
    }

    Rectangle {
        id: bottomSelector

        width: parent.width
        height: parseInt(0.3*mm)
        color: "#33b5e5"

        anchors {
            top: parent.top
            topMargin: pickerList.itemHeight*2
        }
    }

    Rectangle{
        property int m_scale: 50
        height: m_scale
        width: m_scale
        radius: m_scale
        anchors.bottom: parent.bottom
        anchors.bottomMargin: m_scale/2 * -1
        anchors.right: parent.right

        color: "#000000"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                if (parent.color == "#000000")
                {
                    myNetwork.sendUDP("<DP"+((position -4) * -1)+">1")
                    parent.color = "#FF0000"
                }
                else
                {
                    myNetwork.sendUDP("<DP"+((position - 4) * -1)+">0")
                    parent.color = "#000000"
                }
            }
        }
    }
}
