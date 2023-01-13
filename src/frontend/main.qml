import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    color: "#394454"
    title: qsTr("Streamer - v") + Backend.appVersion

    Component.onCompleted: console.log("--> ", Backend.appVersion)
}
