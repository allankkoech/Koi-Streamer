import QtQuick 2.15
import QtQuick.Window 2.15
import "server"

Window {
    width: 800
    height: 480
    visible: true
    color: Theme.backgroundColor
    visibility: "Maximized"
    title: qsTr("Streamer - v") + Backend.appVersion

    Component.onCompleted: console.log("--> ", Backend.appVersion)

    // Toolbar
    Toolbar {

    }
}
