
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "Dir"
  
  function test_it() {
    verify(Dir.value==8)
  }
}
