import QtQuick 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root

    height: 70
    color: Qt.darker(Theme.backgroundColor)

    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right

    RowLayout {
        anchors.fill: parent

        Column {
            Layout.alignment: Qt.AlignVCenter
            Layout.leftMargin: 30

            Text {
                text: "Koi Streamer"
                font.pixelSize: 18
                font.bold: true
                color: Theme.foregroundColor
            }

            Text {
                text: "v" + Backend.appVersion
                font.pixelSize: 12
                color: Theme.textColor
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
        }

        Row {
            Layout.alignment: Qt.AlignVCenter
            Layout.rightMargin: 30
            spacing: 10

            Rectangle {
                width: 30; height: width
                radius: width/2
                color: "red"
                anchors.verticalCenter: parent.verticalCenter
            }

            Column {
                anchors.verticalCenter: parent.verticalCenter

                Text {
                    text: "Status"
                    font.pixelSize: 16
                    color: Theme.foregroundColor
                }

                Text {
                    text: "OFFLINE"
                    font.pixelSize: 12
                    color: Theme.textColor
                }
            }
        }
    }
}
