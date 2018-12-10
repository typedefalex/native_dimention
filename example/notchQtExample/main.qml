import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

import com.yas.NativeDimention 1.0

ApplicationWindow {
	id: window
	visible: true
	width: 360
	height: 640
	title: qsTr("NativeDimention")
	flags: Qt.platform.os === "ios" ? Qt.MaximizeUsingFullscreenGeometryHint : Qt.Window

	header: ToolBar {
		height: NativeDimention.statusBarHeight + 56

		Rectangle {
			color: Material.color(Material.Pink)
			width: parent.width
			height: NativeDimention.statusBarHeight
		}

		RowLayout {
			anchors.fill: parent
			anchors.leftMargin: NativeDimention.insetLeft
			anchors.rightMargin: NativeDimention.insetRight
			anchors.topMargin: NativeDimention.statusBarHeight

			ToolButton { icon.name: "drawer" }
			Label { text: "Title"; elide: Label.ElideRight; horizontalAlignment: Qt.AlignHCenter; verticalAlignment: Qt.AlignVCenter; Layout.fillWidth: true }
			ToolButton { icon.name: "menu" }
		}
	}

	SwipeView {
		id: swipeView
		anchors.fill: parent
		currentIndex: tabBar.currentIndex

		Page {
			Label {
				text: "statusBarHeight: " + NativeDimention.statusBarHeight + "\ninsetBottom: " + NativeDimention.insetBottom + "\ninsetLeft: "
					  + NativeDimention.insetLeft + "\ninsetRight: " + NativeDimention.insetRight + "\ninsetTop: " + NativeDimention.insetTop
				anchors.centerIn: parent
			}
		}

		Page {
			ListView {
				id: list
				anchors.fill: parent
				model: model
				delegate: ItemDelegate {
					id: control
					leftPadding: NativeDimention.insetLeft + 16
					width: list.width
					text: name

					Rectangle{ anchors.fill: parent; color: model.color }
				}
			}

			ListModel {
				id: model

				ListElement { name: "Bill Smith"; color: "red" }
				ListElement { name: "John Brown"; color: "green" }
				ListElement { name: "Sam Wise"; color: "blue" }
				ListElement { name: "Bill Smith"; color: "red" }
				ListElement { name: "John Brown"; color: "green" }
				ListElement { name: "Sam Wise"; color: "blue" }
				ListElement { name: "Bill Smith"; color: "red" }
				ListElement { name: "John Brown"; color: "green" }
				ListElement { name: "Sam Wise"; color: "blue" }
				ListElement { name: "Bill Smith"; color: "red" }
				ListElement { name: "John Brown"; color: "green" }
				ListElement { name: "Sam Wise"; color: "blue" }
			}
		}
	}

	footer: TabBar {
		id: tabBar
		currentIndex: swipeView.currentIndex
		leftPadding: NativeDimention.insetLeft
		rightPadding: NativeDimention.insetRight
		bottomPadding: NativeDimention.insetBottom

		TabButton { icon.name: "menu"; text: qsTr("Page 1") }
		TabButton { icon.name: "drawer"; text: qsTr("Page 2") }
	}
}
