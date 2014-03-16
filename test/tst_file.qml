
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "File"
  
  File { id:file; fileName:"/usr/bin/grep" }
  
  function test_it() {
    compare(file.fileName, "/usr/bin/grep")
    verify(file.exists)
    verify(file.size > 1)
    compare(file.symLinkTarget,"")
  }
  
  function test_open() {
    verify(!file.isOpen())
    verify(file.open(File.ReadOnly))
    verify(file.isOpen())
    file.close()
    verify(!file.isOpen())
  }
}
