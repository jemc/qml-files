
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "Dir"
  
  function init_data() {
    var path = "/test/path"
    var code = 
      "import QtQuick 2.1
       import org.jemc.qml.Files 1.0
       Dir { path:\"%1\" }".arg(path)
    
    return [{dir:Qt.createQmlObject(code, this, "dir")}]
  }
  
  function test_readonly_properties(data) {
    data.dir.path = Dir.tempPath
    compare(data.dir.path,          "/tmp")
    compare(data.dir.absolutePath,  "/tmp")
    compare(data.dir.canonicalPath, "/tmp")
    verify(data.dir.count >= 0)
    compare(data.dir.dirName,       "tmp")
    compare(data.dir.exists,        true)
    compare(data.dir.isAbsolute,    true)
    compare(data.dir.isReadable,    true)
    compare(data.dir.isRelative,    false)
    compare(data.dir.isRoot,        false)
  }
  function test_nameFilters(data) {
    compare(data.dir.nameFilters, ["*"])
    data.dir.nameFilters = ["*.cpp","*.h"]
    compare(data.dir.nameFilters, ["*.cpp","*.h"])
  }
  function test_filter(data) {
    compare(data.dir.filter, Dir.Drives | Dir.Files | Dir.Dirs)
    data.dir.filter = Dir.Drives | Dir.Files | Dir.Dirs | Dir.Hidden
    compare(data.dir.filter, Dir.Drives | Dir.Files | Dir.Dirs | Dir.Hidden)
  }
  function test_sorting(data) {
    compare(data.dir.sorting, Dir.IgnoreCase)
    data.dir.sorting = Dir.IgnoreCase | Dir.Reversed
    compare(data.dir.sorting, Dir.IgnoreCase | Dir.Reversed)
  }
  function test_entryList(data) {
    data.dir.path = Dir.tempPath
    data.dir.mkdir("testdir")
    verify(data.dir.entryList.indexOf("testdir") > -1)
  }
  
  Dir { id:dirHandlesSignals // Verifies that each notify signal exists
    onPathChanged:        { }
    onNameFiltersChanged: { }
    onFilterChanged:      { }
    onSortingChanged:     { }
  }
}
