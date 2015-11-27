//
//  RecordTypes.swift
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/26/15.
//
//

import Foundation

protocol RecordType {
	mutating func port()
	mutating func clearRecordType()
}

struct HorseRecordType: RecordType {
	var location = Location()
	var locationInSec = Location()
	var sector = Location()
	var whichTown: Int16 = 0
	var exists: Bool = false
	var property = false
	
	mutating func port() {
		whichTown = whichTown.bigEndian
	}
	
	mutating func clearRecordType() {
		location = Location()
		locationInSec = Location()
		sector = Location()
		
		whichTown = 0
		exists = false
		property = false
	}
}

struct BoatRecordType: RecordType {
	var location = Location()
	var locationInSec = Location()
	var sector = Location()
	var whichTown: Int16 = 0
	var exists: Bool = false
	var property = false
	
	mutating func port() {
		whichTown = whichTown.bigEndian
	}
	
	mutating func clearRecordType() {
		location = Location()
		locationInSec = Location()
		sector = Location()
		
		whichTown = 0
		exists = false
		property = false
	}
}
