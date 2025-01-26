import Foundation
import CoreBluetooth


class TTToken : NSObject {
    let frame: [UInt8]

    init(frame: [UInt8]) {
        self.frame = frame
    }
    
    func version() -> String {
        return "0x" + String(frame[18], radix:16, uppercase: true)
    }
    
    func id() -> String {
        return "0x" + String(frame[19], radix:16, uppercase: true)
    }
    
    func mac() -> String {
        let value: [UInt8] = Array(frame[0..<6])
        return "0x" + asHexString(value: value)
    }
    
    func companyEncryptedUUID() -> String {
        let value: [UInt8] = Array(frame[6..<16])
        return "0x" + asHexString(value: value)
    }

    func dumpDetails() {
        print("  --> TTToken : seems like this might be one: Version = \(version()) ID = \(id())")
        print("  --> TTToken : companyEncryptedUUID = \(companyEncryptedUUID())")
        print("  --> TTToken : MAC = \(mac())")
    }

    private func asHexString(value: [UInt8]) -> String {
        var retval = ""
        for byte in value {
            var s = String(byte, radix:16, uppercase: true)
            if s.count == 1 {
                s = "0" + s
            }
            retval += s
        }
        return retval
    }

    class func findInFrame(advertisementFrameList: [NSObject : AnyObject]) -> TTToken? {
        let uuid = CBUUID(string: "FFFF")
        if let frameData = advertisementFrameList[uuid] as? NSData {
            let frameSize = frameData.length
            if frameSize == 20 {
                var frameBytes = [UInt8](repeating: 0, count: frameSize)
                frameData.getBytes(&frameBytes, length: frameSize)
                return TTToken(frame: frameBytes)
            }
        }
        return nil
    }
}
