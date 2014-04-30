
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "File Loading"
  
  property var rootPath:
    StandardPaths.writableLocation(StandardPaths.CacheLocation)
  
  Dir { path:rootPath; Component.onCompleted:mkpath(path) }
  File { id:file; fileName:rootPath+"/test.qml" }
  Loader { id:loader; active:false }
  
  function test_it() {
    if(!file.open(File.ReadWrite|File.Truncate))
      console.warn("Couldn't open file at %1 for writing".arg(file.fileName))
    
    file.write('import QtQuick 2.1; QtObject { property var foo: 88 }')
    file.close()
    
    loader.active = true
    loader.source = file.fileName
    
    while(loader.progress < 1) wait(10)
    
    compare(loader.item.foo, 88)
  }
}
