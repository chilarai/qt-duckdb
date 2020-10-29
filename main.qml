import QtQuick 2.15
import QtQuick.Window 2.15
import Qt.labs.platform 1.0


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("DuckDB Test")

    property var listModel : []
    property int textHeight: 20


    // OnComponent load complete, fetch default data from duckCRUD
    Component.onCompleted: {
        listModel = DuckCRUD.readTableData()
        dbDataListView.model = listModel
        dbDataListView.height = listModel.length * textHeight
    }

    ListView{
        id: dbDataListView

        delegate:Text{
            text: modelData
            height: textHeight
        }
    }
}
