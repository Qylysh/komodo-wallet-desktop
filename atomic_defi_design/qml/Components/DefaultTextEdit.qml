import QtQuick 2.15
import "../Constants"

TextEdit {
    property string text_value
    property bool privacy: false

    font.family: Style.font_family
    font.pixelSize: Style.textSize
    text: privacy && General.privacy_mode ? General.privacy_text : text_value
    wrapMode: Text.WordWrap
    selectByMouse: true
    readOnly: true

    selectedTextColor: theme.textSelectedColor
    selectionColor: theme.textSelectionColor
    color: theme.foregroundColor

    Behavior on color { ColorAnimation { duration: Style.animationDuration } }

    onLinkActivated: Qt.openUrlExternally(link)

    DefaultMouseArea {
        anchors.fill: parent
        cursorShape: parent.hoveredLink ? Qt.PointingHandCursor : Qt.ArrowCursor
        acceptedButtons: Qt.NoButton
    }
}
