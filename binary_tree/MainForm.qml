import QtQuick 2.5
import com.qlsystems.binary 1.0

Rectangle {
    id: tree_view
    property int node_radius: 25
    property point node_spawn_point: Qt.point(tree_view.width/2 - node_radius/2, 75 - node_radius/2)

    BinaryTree {
        id: tree
        property bool empty: true
    }

    Component {
        id: visual_node
        Rectangle {
            width: node_radius
            height: width
            radius: height / 2
            border.width: 2
            border.color: "black"

            property QtObject node
            property point visualPosition: node.position

            Text {
                anchors.centerIn: parent
                text: node.value()
            }

            onVisualPositionChanged: {
                console.log("position " + node.position)
                x = visualPosition.x
                y = visualPosition.y
            }

            Behavior on x {
                NumberAnimation { duration: 1000 }
            }

            Behavior on y {
                NumberAnimation { duration: 1000 }
            }
        }
    }

    Rectangle {
        anchors.top: parent.top
        border.width: 1
        border.color: "red"
        width: 90
        height: 15

        TextEdit {
            id: edit
            width: 45
            height: 15
            text: ""
        }

        Text {
            anchors.left: edit.right
            width: 45
            height: 15
            text: "add"

            MouseArea {
                id: mouseArea
                width: 45
                height: 15

                onClicked: {
                    var node = tree.node(parseInt(edit.getText(0, edit.length), 10))
                    if (tree.empty) {
                        node.offset = "200,40"
                        tree.empty = false
                    }
                    var v_node = visual_node.createObject(tree_view, {"node": node});
                    v_node.node.position = Qt.point(node_spawn_point.x, node_spawn_point.y)
                    if (!tree.insert(node)) {
                        v_node.destroy()
                        node.destroy()
                    }
                    edit.text = ""
                }
            }
        }
    }
}

