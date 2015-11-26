//
//  Rect.swift
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

import Foundation

/// Defined as a Swift struct because Swift doesn't import MacTypes.h's `Rect`.
struct Rect {
	var top: Int16 = 0
	var left: Int16 = 0
	var bottom: Int16 = 0
	var right: Int16 = 0
}
