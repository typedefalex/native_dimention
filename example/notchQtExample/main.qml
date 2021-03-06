/*
 *  Copyright © 2018-2019 Alex Yakubinskiy. All rights reserved. Contacts: <prktown.work@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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

                    Rectangle{
                        anchors.fill: parent
                        color: switch (index % 3) {
                                   case 0: return Material.color(Material.Red);
                                   case 1: return Material.color(Material.Green);
                                   case 2: return Material.color(Material.Blue);
                               }
                    }
				}
			}

			ListModel {
				id: model

                ListElement { name: "Bill Smith" }
                ListElement { name: "John Brown"; }
                ListElement { name: "Sam Wise"; }
                ListElement { name: "Bill Smith"; }
                ListElement { name: "John Brown"; }
                ListElement { name: "Sam Wise"; }
                ListElement { name: "Bill Smith"; }
                ListElement { name: "John Brown"; }
                ListElement { name: "Sam Wise"; }
                ListElement { name: "Bill Smith"; }
                ListElement { name: "John Brown"; }
                ListElement { name: "Sam Wise"; }
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
