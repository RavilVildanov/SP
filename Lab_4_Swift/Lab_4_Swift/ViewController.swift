//
//  ViewController.swift
//  Lab_4_Swift
//
//  Created by Равиль Вильданов on 14/05/2019.
//  Copyright © 2019 Vildanov. All rights reserved.
//

import UIKit

struct Stack<Element> {
    var items = [Element]()
    mutating func push(_ item: Element) {
        items.append(item)
    }
    mutating func pop() -> Element {
        return items.removeLast()
    }
}

class MyArray<Element: Comparable> {
    private var items = [Element]()
    
    func sort() {
        items.sort(by: <)
    }
    
    func append(item: Element) {
        self.items.append(item)
    }
    
    func show() {
        print(self.items)
    }
}

class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let ints = MyArray<Int>()
        let doubles = MyArray<Double>()
        let strings = MyArray<String>()
        
        ints.append(item: 2)
        ints.append(item: 3)
        ints.append(item: 1)
        
        doubles.append(item: 7.0)
        doubles.append(item: 6.0)
        doubles.append(item: 5.0)
        
        strings.append(item: "ccc")
        strings.append(item: "bbb")
        strings.append(item: "aaa")
        
        ints.show()
        doubles.show()
        strings.show()
        
        ints.sort()
        doubles.sort()
        strings.sort()
        
        print("\nПосле сортировки:\n")
        ints.show()
        doubles.show()
        strings.show()
    }
}

