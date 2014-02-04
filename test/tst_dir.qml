
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "Dir"
  
  function test_it() {
    verify(Dir.cleanPath("/test/path").length > 0)
    verify(Dir.currentPath().length > 0)
    verify(Dir.fromNativeSeparators("/test/path").length > 0)
    verify(Dir.homePath().length > 0)
    verify(Dir.rootPath().length > 0)
    verify(Dir.separator().length == 1)
    verify(Dir.tempPath().length > 0)
    verify(Dir.fromNativeSeparators("\\test\\path").length > 0)
    console.log(Dir.currentPath())
    console.log(Dir.current().path())
  }
}
