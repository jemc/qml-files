
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "File Loading"
  
  property var rootPath:
    StandardPaths.writableLocation(StandardPaths.CacheLocation)
  
  Loader { id:loader; active:false }
  
  function test_loading() {
    Dir._(rootPath).mkpath(rootPath)
    var file_test  = File._(rootPath+"/test.qml")
    var file_Other = File._(rootPath+"/Other.qml")
    
    if(!file_Other.open(File.ReadWrite|File.Truncate))
      console.warn("Couldn't open file at %1 for writing".arg(file_Other.fileName))
    
    file_Other.write('import QtQuick 2.1; QtObject { property var foo: 99 }')
    file_Other.close()
    
    if(!file_test.open(File.ReadWrite|File.Truncate))
      console.warn("Couldn't open file at %1 for writing".arg(file_test.fileName))
    
    file_test.write("import QtQuick 2.1; Other { property var bar: 88 }")
    file_test.close()
    
    loader.active = true
    loader.source = file_test.fileName
    
    while(loader.progress < 1) wait(10)
    
    compare(loader.item.foo, 99)
    compare(loader.item.bar, 88)
  }
}
