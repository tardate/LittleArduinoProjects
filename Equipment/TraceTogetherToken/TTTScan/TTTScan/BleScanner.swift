import Foundation


class BleScanner {
    var manager = BleManager()
    var running = false

    func scan() {
        print("Scan start...")

        running = true
        let sem = DispatchSemaphore.init(value: 0);

        manager.startScan(completionHandler: {
            sem.signal()
        })

        sem.wait()
        print("End scan.")
    }
}
