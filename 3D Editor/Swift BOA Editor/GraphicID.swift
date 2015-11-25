//
//  GraphicID.swift
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

import Foundation

/// The data for the location for an icon in memory.
struct GraphicIDType {
	/// the resource number of the graphic
	var whichSheet: Int16 = -1
	/// the icon in the resource. icons are in resources
	/// 16 icons per row
	var whichIcon: Int16 = 0
	var graphicAdjust: Int16 = 0
	
	var isNotLegit: Bool {
		if whichSheet < 0 {
			return true
		} else if whichIcon < 0 {
			return true
		}
		
		return false
	}

	mutating func clear() {
		whichSheet = -1
		whichIcon = 0
		graphicAdjust = 0
	}
}
