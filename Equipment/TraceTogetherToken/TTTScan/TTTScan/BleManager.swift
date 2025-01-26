import CoreBluetooth
import Cocoa


class BleManager: NSObject, CBCentralManagerDelegate, CBPeripheralDelegate {
    var centralManager: CBCentralManager
    fileprivate var writeCompletionHandler: (() -> Void)?

    func startScan(completionHandler: (() -> Void)? = nil) {
        writeCompletionHandler = completionHandler
        centralManager = CBCentralManager(delegate: self, queue: DispatchQueue.global(qos: .background))
    }
    
    override init() {
        self.centralManager = CBCentralManager(delegate: nil, queue: nil)
        super.init()
        self.centralManager.delegate = self
    }
 
    // Required. Invoked when the central manager’s state is updated.
    func centralManagerDidUpdateState(_ manager: CBCentralManager) {
        switch manager.state {
        case .poweredOff:
            print("BLE has powered off")
            centralManager.stopScan()
        case .poweredOn:
            print("BLE is now powered on")
            centralManager.scanForPeripherals(withServices: nil, options: nil)
        case .resetting: print("BLE is resetting")
        case .unauthorized: print("Unauthorized BLE state")
        case .unknown: print("Unknown BLE state")
        case .unsupported: print("This platform does not support BLE")
        }
    }

    // Invoked when the central manager discovers a peripheral while scanning.
    func centralManager(_ manager: CBCentralManager, didDiscover peripheral: CBPeripheral, advertisementData advertisement: [String: Any], rssi: NSNumber) {

        let identifier = peripheral.value(forKey: "identifier") as! NSUUID as UUID
        let name = peripheral.name ?? "n/a"
        
        print("Device : \(identifier) - RSSI : \(rssi) DeviceName : \(name)")

        if let serviceData = advertisement[CBAdvertisementDataServiceDataKey] as? [NSObject:AnyObject]{
            print("  --> serviceData : \(serviceData) ")
            
            if let ttt = TTToken.findInFrame(advertisementFrameList: serviceData) {
                ttt.dumpDetails()
            }
        }
    }
}
