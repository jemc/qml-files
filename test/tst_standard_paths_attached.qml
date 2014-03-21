
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "StandardPaths"
  
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
  
  function test_writableLocation() {
    for(var type in types) {
      var path = StandardPaths.writableLocation(type)
      console.log(path)
      verify(path.length > 0)
    }
  }
}