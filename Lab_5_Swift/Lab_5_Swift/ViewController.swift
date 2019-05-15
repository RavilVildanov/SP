//
//  ViewController.swift
//  Lab_5_Swift
//
//  Created by Равиль Вильданов on 14/05/2019.
//  Copyright © 2019 Vildanov. All rights reserved.
//

import UIKit

class Cargo {
    var speed: Double
    var price: Double
    
    init(speed: Double = 10, price: Double = 1) {
        self.speed = speed
        self.price = price
    }
    
    func show() {
        print("speed: \(speed)")
        print("price: \(price)")
    }
    
    func calculatePriceFor(distance: Double) {
        print("Price for \(distance) km = \(price * distance)")
    }
    
    func calculateTimeFor(distance: Double) {
        print("Time for \(distance) km = \(distance / speed)")
    }
}

class Airplane: Cargo {
    override func show() {
        print("Airplane:")
        super.show()
    }
    
    override func calculateTimeFor(distance: Double) {
        // добавим время на посадку/погрузку
        print("Time for \(distance) km = \(distance / speed + 1.0) hours")
    }
}

class Train: Cargo {
    override func show() {
        print("Train:")
        super.show()
    }
}

class Auto: Cargo {
    override func show() {
        print("Auto:")
        super.show()
    }
}

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let airplane = Airplane(speed: 150, price: 50)
        let train = Train(speed: 70, price: 10)
        let auto = Auto(speed: 100, price: 20)
        
        print("Times: ")
        
        airplane.calculateTimeFor(distance: 800)
        train.calculateTimeFor(distance: 800)
        auto.calculateTimeFor(distance: 800)
        
        print("Prices: ")
        
        airplane.calculatePriceFor(distance: 800)
        train.calculatePriceFor(distance: 800)
        auto.calculatePriceFor(distance: 800)
        
    }
}

