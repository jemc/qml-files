
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "StandardPathsAttached"
  
  property var types: [
    StandardPaths.DesktopLocation,
    StandardPaths.DocumentsLocation,
    StandardPaths.FontsLocation,
    StandardPaths.ApplicationsLocation,
    StandardPaths.MusicLocation,
    StandardPaths.MoviesLocation,
    StandardPaths.PicturesLocation,
    StandardPaths.TempLocation,
    StandardPaths.HomeLocation,
    StandardPaths.DataLocation,
    StandardPaths.CacheLocation,
    StandardPaths.GenericCacheLocation,
    StandardPaths.GenericDataLocation,
    StandardPaths.RuntimeLocation,
    StandardPaths.ConfigLocation,
    StandardPaths.GenericConfigLocation,
    StandardPaths.DownloadLocation,
  ]
  
  function test_displayName() {
    for(var type in types) {
      var descrip = StandardPaths.displayName(type)
      verify(descrip.length > 0)
    }
  }
  
  function test_findExecutable() {
    var paths = StandardPaths.findExecutable("grep")
    verify(paths.length > 0)
    for(var path in paths)
      verify(path.length > 0)
  }
  
  function test_writableLocation() {
    for(var type in types) {
      var path = StandardPaths.writableLocation(type)
      verify(path.length > 0)
    }
  }
  
  function test_standardLocations() {
    for(var type in types) {
      var paths = StandardPaths.standardLocations(type)
      verify(paths.length > 0)
      for(var path in paths)
        verify(path.length > 0)
    }
  }
  
  function test_testMode_writableLocation() {
    var allSame = true
    for(var type in types) {
      var path1 = StandardPaths.writableLocation(type)
      StandardPaths.setTestModeEnabled(true)
      var path2 = StandardPaths.writableLocation(type)
      StandardPaths.setTestModeEnabled(false)
      verify(path2.length > 0)
      allSame = allSame && (path1 == path2)
    }
    verify(!allSame)
  }
}