
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "File"
  
  File { id:grep; fileName:"/usr/bin/grep" }
  File { id:file; fileName:"/tmp/qfile" }
  
  function test_it() {
    compare(grep.fileName, "/usr/bin/grep")
    verify(grep.exists)
    verify(grep.size > 1)
    compare(grep.symLinkTarget,"")
  }
  
  function test_open_close() {
    verify(!file.isOpen)
    verify(file.open(File.ReadWrite))
    verify(file.isOpen)
    file.close()
    verify(!file.isOpen)
  }
  
  function test_write_read_peek() {
    verify(file.open(File.ReadWrite|File.Truncate))
    
    var test_strings = [
      ['test',    4], // Normal latin1 encoded string
      ['xx%00zz', 5], // String with null byte in the center
    ]
    
    for(var i=0; i<test_strings.length; i++) {
      var string     = test_strings[i][0]
      var byteLength = test_strings[i][1]
      
      // Write, then reset
      var bytesWritten = file.write(string)
      compare(bytesWritten, byteLength,        "for string: \"%1\"".arg(string))
      verify(file.reset(),                     "for string: \"%1\"".arg(string))
      
      // Peek
      compare(file.peek(bytesWritten), string, "for string: \"%1\"".arg(string))
      
      // Read, then reset
      compare(file.read(bytesWritten), string, "for string: \"%1\"".arg(string))
      verify(file.reset(),                     "for string: \"%1\"".arg(string))
    }
    
    file.close()
  }
  
  function test_readAll_truncate_readLine() {
    verify(file.open(File.ReadWrite|File.Truncate))
    compare(file.readAll(), "")
    compare(file.write("test"), 4)
    verify(file.reset())
    compare(file.readAll(), "test")
    file.close()
    
    verify(file.open(File.ReadWrite|File.Truncate))
    compare(file.readAll(), "")
    file.close()
    
    verify(file.open(File.ReadWrite|File.Truncate))
    compare(file.readAll(), "")
    compare(file.write("test\n"), 5)
    compare(file.write("the_"), 4)
    compare(file.write("rest\n"), 5)
    verify(file.reset())
    compare(file.readLine(), "test%0A")
    compare(file.readLine(), "the_rest%0A")
    verify(file.reset())
    compare(file.readLine(4), "test")
    compare(file.readLine(), "%0A")
    compare(file.readLine(4), "the_")
    compare(file.readLine(), "rest%0A")
    file.close()
  }
  
  function test_pos_bytesAvailable_size_seek_resize() {
    verify(file.open(File.ReadWrite|File.Truncate))
    compare(file.write("foo_bar_baz"), 11)
    
    compare(file.pos,            11)
    compare(file.bytesAvailable, 0)
    compare(file.size,           11)
    
    verify(file.reset())
    
    compare(file.pos,            0)
    compare(file.bytesAvailable, 11)
    compare(file.size,           11)
    
    compare(file.read(4), "foo_")
    
    compare(file.pos,            4)
    compare(file.bytesAvailable, 7)
    compare(file.size,           11)
    
    verify(file.seek(8))
    
    compare(file.pos,            8)
    compare(file.bytesAvailable, 3)
    compare(file.size,           11)
    
    compare(file.readAll(), "baz")
    verify(file.resize(3))
    verify(file.reset())
    
    compare(file.pos,            0)
    compare(file.bytesAvailable, 3)
    compare(file.size,           3)
    
    compare(file.readAll(), "foo")
    file.close()
  }
  
  function test_permissions() {
    verify((grep.permissions & File.ReadUser))
    verify(!(grep.permissions & File.WriteUser))
    verify((grep.permissions & File.ExeUser))
    
    verify((file.permissions & File.ReadUser))
    verify((file.permissions & File.WriteUser))
    verify(!(file.permissions & File.ExeUser))
  }
}
