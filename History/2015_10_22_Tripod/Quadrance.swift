//
//  Quadrance.swift
//  OVS3D
//
//  Created by Stijn Oomes on 22/10/15.
//  Copyright © 2015 Oomes Vision Systems. All rights reserved.
//

import Foundation

struct Quadrance: Equatable {
    
    var value: Rational
    
    init() {
        self.value = Rational()
    }
    
    init(p1: Point2D, p2: Point2D) {
        
        let diff: Point2D = p1 - p2
        self.value = diff * diff
    }

    
    // other inits:
    //
    // from two points
    // from double
    // from int
    
    func fromDistance(distance: Double) -> Int? {
        
        if distance < 0.0 {
            return nil
        }
        
        let maxDistance = sqrt(Double(Int.max)) // turn Int into unsigned UInt for larger maximum distance
        if distance >= maxDistance {
            return nil
        }
        
        return Int(distance * distance)
    }
    
}

func ==(left: Quadrance, right: Quadrance) -> Bool {
    
    return left.value == right.value
}

