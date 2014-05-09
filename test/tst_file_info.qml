
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "FileInfo"
  
  function test_attached_exists() {
    verify(FileInfo.exists(Dir.homePath))
  }
  function test_convenience_constructor() {
    var fileInfo = FileInfo._(Dir.homePath)
    verify(fileInfo.exists)
    verify(fileInfo.isDir)
    verify(!fileInfo.isFile)
  }
}
