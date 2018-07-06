
import QtQuick 2.0

Rectangle {
    id: rootRect
    property int mm: 13
    property double itemHeight: 8*mm
    property alias model: listView.model

    signal indexChanged(int value)

    function setValue(value) {
        listView.currentIndex = value
        listView.positionViewAtIndex(value, ListView.Center);
    }

    ListView {
        id: listView

        clip: true
        anchors.fill: parent
        contentHeight: itemHeight*3

        delegate: Item {
            property var isCurrent: ListView.isCurrentItem
            id: item

            height: itemHeight
            width:  listView.width

            Rectangle {
                anchors.fill: parent

                Text {
                    text: model.text
                    font.pixelSize: 3*mm
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        rootRect.gotoIndex(model.index)
                    }
                }
            }
        }
        onMovementStarted: {
            //MY....
                               timer.start()
        }

        onMovementEnded: {
            var centralIndex = listView.indexAt(listView.contentX+1,listView.contentY+itemHeight+itemHeight/2)
            gotoIndex(centralIndex)
            indexChanged(currentIndex)
            //MY....
            timer.stop()
        }
    }

    //MY....
    Timer{
        id: timer
        interval: 100
        running: false
        repeat: true
        onTriggered: {
            if(anim.running != true)
            {

                var inIndex = listView.indexAt(listView.contentX+1,listView.contentY+itemHeight+itemHeight/2)
                indexChanged(inIndex-1)
            }

        }
    }

    function gotoIndex(inIndex) {
        var begPos = listView.contentY;
        var destPos;

        listView.positionViewAtIndex(inIndex, ListView.Center);
        destPos = listView.contentY;

        anim.from = begPos;
        anim.to = destPos;
        anim.running = true;

        listView.currentIndex = inIndex
    }

    function mygotoIndex(inIndex) {
        var begPos = listView.contentY;
        var destPos;

        listView.positionViewAtIndex(inIndex, ListView.Center);
        destPos = listView.contentY;

        anim.from = begPos;
        anim.to = destPos;
        anim.running = true;

        listView.currentIndex = inIndex
    }

    NumberAnimation {
        id: anim;

        target: listView;
        property: "contentY";
        easing {
            type: Easing.OutInExpo;
            overshoot: 50
        }
    }

    function next() {
        gotoIndex(listView.currentIndex+1)
    }

    function prev() {
        gotoIndex(listView.currentIndex-1)
    }
}
