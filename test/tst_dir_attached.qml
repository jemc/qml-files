
import QtTest 1.0
import QtQuick 2.1

import org.jemc.qml.Files 1.0

TestCase {
  id: test
  name: "DirAttached"
  
  
  function test_separator() {
    compare(Dir.separator, "/")
  }
  function test_clean_and_native() {
    compare(Dir.cleanPath("/some//strange\ path"), "/some/strange path")
    compare(Dir.fromNativeSeparators("/test/path"), "/test/path")
    compare(Dir.toNativeSeparators("/test/path"), "/test/path")
  }
  function test_globalPaths() {
    verify(Dir.currentPath.length > 0)
    verify(Dir.homePath.length > 0)
    verify(Dir.rootPath.length > 0)
    verify(Dir.tempPath.length > 0)
    compare(Dir.currentPath,Dir.current.path)
    compare(Dir.homePath,Dir.home.path)
    compare(Dir.rootPath,Dir.root.path)
    compare(Dir.tempPath,Dir.temp.path)
  }
  function test_setCurrentPath() {
    verify(Dir.currentPath != Dir.tempPath)
    Dir.setCurrent(Dir.tempPath)
    verify(Dir.currentPath == Dir.tempPath)
  }
  function test_searchPaths() {
    compare(Dir.searchPaths("stuff"), [])
    Dir.addSearchPath("stuff", "/test/path")
    Dir.addSearchPath("stuff", "/test/other/path")
    compare(Dir.searchPaths("stuff"), ["/test/path","/test/other/path"])
    Dir.setSearchPaths("stuff", ["/other/path","/other/other/path"])
    compare(Dir.searchPaths("stuff"), ["/other/path","/other/other/path"])
    Dir.setSearchPaths("stuff", [])
    compare(Dir.searchPaths("stuff"), [])
  }
  function test_isAbsolutePath() {
    compare(Dir.isAbsolutePath("/test/path"), true)
    compare(Dir.isAbsolutePath("test/path"), false)
    compare(Dir.isAbsolutePath("./test/path"), false)
    compare(Dir.isAbsolutePath("../test/path"), false)
  }
  function test_match() {
    compare(Dir.match("/tmp/*.cpp", "/tmp/thing.cpp"), true)
    compare(Dir.match("/tmp/*.cpp", "/tmp/thing.h"), false)
    compare(Dir.match("/**/*.cpp", "/tmp/thing.cpp"), true)
    compare(Dir.match("/**/*.cpp", "/tmp/thing.h"), false)
  }
  function test_filter_enum() {
    compare(Dir.Drives | Dir.Files | Dir.Dirs, 7)
  }
  function test_sortflags_enum() {
    compare(Dir.IgnoreCase | Dir.Reversed, 24)
  }
}
