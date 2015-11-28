//
//  RecordTypes.swift
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/26/15.
//
//

import Foundation

protocol BoAPortableType {
	mutating func port()
	mutating func clear()
}

struct HorseRecordType: BoAPortableType {
	var location = Location()
	var locationInSec = Location()
	var sector = Location()
	var whichTown: Int16 = 0
	var exists: Bool = false
	var property = false
	
	mutating func port() {
		whichTown = whichTown.bigEndian
	}
	
	mutating func clear() {
		location = Location()
		locationInSec = Location()
		sector = Location()
		
		whichTown = 0
		exists = false
		property = false
	}
}

struct BoatRecordType: BoAPortableType {
	var location = Location()
	var locationInSec = Location()
	var sector = Location()
	var whichTown: Int16 = 0
	var exists: Bool = false
	var property = false
	
	mutating func port() {
		whichTown = whichTown.bigEndian
	}
	
	mutating func clear() {
		location = Location()
		locationInSec = Location()
		sector = Location()
		
		whichTown = 0
		exists = false
		property = false
	}
}

struct ItemStorageShortcutType {
	var terType: Int16 = 0
	var itemNum: (Int16,Int16,Int16,Int16,Int16,Int16,Int16,Int16,Int16,Int16) = (0,0,0,0,0,0,0,0,0,0)
	var itemOdds: (Int16,Int16,Int16,Int16,Int16,Int16,Int16,Int16,Int16,Int16) = (0,0,0,0,0,0,0,0,0,0)
	var property: Int16 = 0
}

struct ItemType: BoAPortableType {
	struct Properties: OptionSetType {
		let rawValue: UInt8
		
		init(rawValue rv: UInt8) {
			rawValue = rv
		}
		
		static let Identified = Properties(rawValue: 1 << 0)
		static let Property = Properties(rawValue: 1 << 1)
		static let Contained = Properties(rawValue: 1 << 2)
		static let Cursed = Properties(rawValue: 1 << 3)
		static let UsedToday = Properties(rawValue: 1 << 4)
	}
	
	mutating func clear() {
		
	}
	
	var exists: Bool {
		return whichItem >= 0
	}
	
	mutating func port() {
		
	}
	
	/// -1 - null item
	/// if 0 - 399, item from scenario list
	/// if 1000 + x, is item x is party imported_items list
	var whichItem: Int16 = -1
	var item_loc = Location()
	var charges: UInt8 = 0
	var properties: Properties = []
	var itemShift = Location()
};


class TrType {
	let elementSize: Int
	var terrain: [[Int16]]
	var floor: [[UInt8]]
	var height: [[UInt8]]
	var lighting: [[UInt8]]
	
	enum TerrainSize: Int {
		case Big = 64
		case Average = 48
		case Tiny = 32
	}
	
	init(elementSize eSiz: TerrainSize) {
		self.elementSize = eSiz.rawValue
		terrain = [[Int16]](count: elementSize, repeatedValue: [Int16](count: elementSize, repeatedValue: 0))
		floor = [[UInt8]](count: elementSize, repeatedValue: [UInt8](count: elementSize, repeatedValue: 0))
		height = [[UInt8]](count: elementSize, repeatedValue: [UInt8](count: elementSize, repeatedValue: 0))
		lighting = [[UInt8]](count: elementSize, repeatedValue: [UInt8](count: elementSize, repeatedValue: 0))
	}
	
	convenience init?(elementSize eSiz: TerrainSize, data: NSData) {
		self.init(elementSize:eSiz)
	}
	
	func clear() {
		terrain = [[Int16]](count: elementSize, repeatedValue: [Int16](count: elementSize, repeatedValue: 0))
		floor = [[UInt8]](count: elementSize, repeatedValue: [UInt8](count: elementSize, repeatedValue: 0))
		height = [[UInt8]](count: elementSize, repeatedValue: [UInt8](count: elementSize, repeatedValue: 0))
		lighting = [[UInt8]](count: elementSize, repeatedValue: [UInt8](count: elementSize, repeatedValue: 0))
	}
	
	func saveData() -> NSData? {
		let toSaveSize = sizeof(Int16) * elementSize * elementSize + sizeof(UInt8) * elementSize * elementSize + sizeof(UInt8) * elementSize * elementSize + sizeof(UInt8) * elementSize * elementSize
		
		guard let mutDat = NSMutableData(capacity: toSaveSize) else {
			return nil
		}
		
		for a in terrain {
			for b in a {
				var byteswapped = b.bigEndian
				mutDat.appendBytes(&byteswapped, length: sizeof(Int16))
			}
		}
		
		for a in floor {
			mutDat.appendBytes(a, length: sizeof(UInt8) * a.count)
		}
		
		for a in height {
			mutDat.appendBytes(a, length: sizeof(UInt8) * a.count)
		}

		for a in lighting {
			mutDat.appendBytes(a, length: sizeof(UInt8) * a.count)
		}
		
		return NSData(data: mutDat)
	}
}
