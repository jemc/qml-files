
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "Dir"
  
  Dir {id:subject}
  
  function test_it() {
    verify(subject.value==8)
  }
}
