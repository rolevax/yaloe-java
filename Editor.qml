import QtQuick 2.0
import QtQuick.Dialogs 1.2
import sell 1.0

Rectangle {
    property string filename

    id: frame
    width: 800; height: 500
    color: "#222233"
    focus: true

    PDoc {
        id: pDoc

        onMessage: {
            messageDialog.text = text;
            messageDialog.open();
        }

        onTension: {
            street.setTension(b);
        }

        onPushed: {
            modesModel.append({ modelText: name });
        }

        onPopped: {
            modesModel.remove(modesModel.count - 1, 1);
        }

        onInsertLine: { street.insertLine(r, ct); }
        onRemoveLine: { street.removeLine(r, ct); }
        onUpdateLine: { street.updateLine(r, str); }
        onHotLighted: { street.setHotLight(back); }
        onLighted: {
            street.light(false, lbr, lbc, ler, lec);
            street.light(true, hbr, hbc, her, hec);
        }
    }

    Street {
        id: street
        anchors.fill: parent
    }

    ListView {
        id: modes
        model: ListModel {
            id: modesModel
        }

        width: 130
        height: parent.height
        anchors.right: parent.right
        verticalLayoutDirection: ListView.BottomToTop
        delegate: Rectangle {
            width: parent.width
            height: 35
            color: "yellow"
            Text {
                anchors.centerIn: parent
                text: modelText
                font.pixelSize: 20
            }
        }
    }

    MessageDialog {
        id: messageDialog
        icon: StandardIcon.Information
    }

    Keys.onPressed: {
        pDoc.keyboard(event.text, event.modifiers);
        event.accepted = true;
    }

    onFilenameChanged: {
        pDoc.load(filename);
    }

    function save() {
        pDoc.save(filename);
    }
}

