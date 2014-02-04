
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "Dir"
  
  function test_it() {
    verify(Dir.cleanPath("/test/path").length > 0)
    verify(Dir.fromNativeSeparators("/test/path").length > 0)
    verify(Dir.separator().length == 1)
    verify(Dir.fromNativeSeparators("\\test\\path").length > 0)
    
    verify(Dir.currentPath().length > 0)
    verify(Dir.homePath().length > 0)
    verify(Dir.rootPath().length > 0)
    verify(Dir.tempPath().length > 0)
    
    compare(Dir.currentPath(),Dir.current().path())
    compare(Dir.homePath(),Dir.home().path())
    compare(Dir.rootPath(),Dir.root().path())
    compare(Dir.tempPath(),Dir.temp().path())
    
    Dir.addSearchPath("stuff", "/test/path")
    Dir.addSearchPath("stuff", "/test/other/path")
    compare(Dir.searchPaths("stuff"),["/test/path","/test/other/path"])
  }
}
