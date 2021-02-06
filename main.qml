import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("DuckDB Test")

    property var listModel : []
    property int textHeight: 20
    property int btnCount: 5


    // Signal received on any change in data (insert/update/delete)
    Connections{
        target: DuckCRUD

        function onDataUpdated(){
            loadData()
        }
    }

    // OnComponent load complete, fetch default data from DuckCRUD
    Component.onCompleted: loadData()


    function loadData(){
        listModel = DuckCRUD.readTableData()
        dbDataListView.model = listModel
        dbDataListView.height = listModel.length * textHeight
    }



    Row{
        id: btnList
        height:50
        width: parent.width
        spacing: 1

        Button{
            width: btnList.width / btnCount
            Text {
                id: addDataBtn
                text: qsTr("Add Data")
                anchors.centerIn: parent
            }

            // Will add a new test data
            onClicked: DuckCRUD.insertData()
        }

        Button{
            width: btnList.width / btnCount
            Text {
                id: deleteDataBtn
                text: qsTr("Delete Data")
                anchors.centerIn: parent
            }

            // Will delete the last data
            onClicked: DuckCRUD.deleteData()
        }

        Button{
            width: btnList.width / btnCount
            Text {
                id: updateDataBtn
                text: qsTr("Update Data")
                anchors.centerIn: parent
            }

            // Will update the last data
            onClicked: DuckCRUD.updateData()
        }

        Button{
            width: btnList.width / btnCount
            Text {
                id: readCsv
                text: qsTr("Read CSV")
                anchors.centerIn: parent
            }

            // Will read csv from an absolute path
            onClicked: DuckCRUD.processCsv()
        }

        Button{
            width: btnList.width / btnCount
            Text {
                id: childClassCall
                text: qsTr("Debug From ChildClass")
                anchors.centerIn: parent
            }

            // Will read csv from an absolute path
            onClicked: ChildCRUD.callChild()
        }
    }

    ListView{
        id: dbDataListView
        anchors.top: btnList.bottom

        delegate:Text{
            text: modelData
            height: textHeight
        }
    }

}
