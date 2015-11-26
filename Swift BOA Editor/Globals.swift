//
//  Globals.swift
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

import Foundation

enum SelectionType {
	case None
	//MARK: Town only:
	case Creature
	case Item
	case TerrainScript
	case Waypoint
	//MARK: Town or outdoor:
	case SpecialEncounter
	case AreaDescription
	case Sign
	//MARK: Outdoor only:
	case TownEntrance
}

