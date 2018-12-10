import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

import com.yas.NativeDimention 1.0

ApplicationWindow {
	visible: true
	width: 640
	height: 480
	title: qsTr("Hello World")
	flags: Qt.platform.os === "ios" ? Qt.Window | Qt.MaximizeUsingFullscreenGeometryHint : Qt.Window

	header: ToolBar {
		Material.accent: "red"
		Material.background: "red"
		Material.foreground: "red"
		Material.primary: "red"

		leftPadding: NativeDimention.insetLeft

		height: NativeDimention.statusBarHeight + 56

		Rectangle {
			color: "red"
			width: parent.width
			height: NativeDimention.statusBarHeight
		}



		RowLayout {
			anchors.fill: parent
			anchors.topMargin: NativeDimention.statusBarHeight
			ToolButton {
				text: qsTr("‹")
				onClicked: stack.pop()
			}
			Label {
				text: "Title"
				elide: Label.ElideRight
				horizontalAlignment: Qt.AlignHCenter
				verticalAlignment: Qt.AlignVCenter
				Layout.fillWidth: true
			}
			ToolButton {
				text: qsTr("⋮")
				onClicked: menu.open()
			}
		}
	}

	ListView {
		id: list
		 anchors.fill: parent

		 model: model
		 delegate: ItemDelegate {
			 id: control
			 leftPadding: NativeDimention.insetLeft
			 width: list.width


			 text: name

			 Rectangle{
				 anchors.fill: parent
				 color: model.color
			 }
		 }
	 }


	ListModel {
		id: model

			ListElement {
				name: "Bill Smith"
				color: "red"
			}
			ListElement {
				name: "John Brown"
				color: "green"
			}
			ListElement {
				name: "Sam Wise"
				color: "blue"
			}

			ListElement {
				name: "Bill Smith"
				color: "red"
			}
			ListElement {
				name: "John Brown"
				color: "green"
			}
			ListElement {
				name: "Sam Wise"
				color: "blue"
			}
			ListElement {
				name: "Bill Smith"
				color: "red"
			}
			ListElement {
				name: "John Brown"
				color: "green"
			}
			ListElement {
				name: "Sam Wise"
				color: "blue"
			}
			ListElement {
				name: "Bill Smith"
				color: "red"
			}
			ListElement {
				name: "John Brown"
				color: "green"
			}
			ListElement {
				name: "Sam Wise"
				color: "blue"
			}
			ListElement {
				name: "Bill Smith"
				color: "red"
			}
			ListElement {
				name: "John Brown"
				color: "green"
			}
			ListElement {
				name: "Sam Wise"
				color: "blue"
			}
			ListElement {
				name: "Bill Smith"
				color: "red"
			}
			ListElement {
				name: "John Brown"
				color: "green"
			}
			ListElement {
				name: "Sam Wise"
				color: "blue"
			}
			ListElement {
				name: "Bill Smith"
				color: "red"
			}
			ListElement {
				name: "John Brown"
				color: "green"
			}
			ListElement {
				name: "Sam Wise"
				color: "blue"
			}

	}

	Text{
		anchors.fill: parent
		text: NativeDimention.statusBarHeight + " " + NativeDimention.insetBottom + " " + NativeDimention.insetLeft + " " + NativeDimention.insetRight + " " + NativeDimention.insetTop
	}
}
