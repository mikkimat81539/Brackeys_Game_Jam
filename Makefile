build:
	g++ -g main.cpp gameplay.cpp gameover.cpp assets.cpp $$(pkg-config --libs --cflags raylib) -o GetOffMyLawn

app: build
	rm -rf GetOffMyLawn.app
	mkdir -p GetOffMyLawn.app/Contents/MacOS
	mkdir -p GetOffMyLawn.app/Contents/Resources
	mkdir -p GetOffMyLawn.app/Contents/Frameworks

	cp GetOffMyLawn GetOffMyLawn.app/Contents/MacOS/GetOffMyLawn
	cp assets/icon.icns GetOffMyLawn.app/Contents/Resources/icon.icns
	cp /opt/homebrew/opt/raylib/lib/libraylib.600.dylib GetOffMyLawn.app/Contents/Frameworks/

	install_name_tool -change \
	/opt/homebrew/opt/raylib/lib/libraylib.600.dylib \
	@executable_path/../Frameworks/libraylib.600.dylib \
	GetOffMyLawn.app/Contents/MacOS/GetOffMyLawn

	printf '%s\n' \
	'<?xml version="1.0" encoding="UTF-8"?>' \
	'<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">' \
	'<plist version="1.0">' \
	'<dict>' \
	'<key>CFBundleName</key>' \
	'<string>Get Off My Lawn</string>' \
	'<key>CFBundleDisplayName</key>' \
	'<string>Get Off My Lawn</string>' \
	'<key>CFBundleExecutable</key>' \
	'<string>GetOffMyLawn</string>' \
	'<key>CFBundleIdentifier</key>' \
	'<string>com.getoffmylawn.game</string>' \
	'<key>CFBundleIconFile</key>' \
	'<string>icon.icns</string>' \
	'<key>CFBundlePackageType</key>' \
	'<string>APPL</string>' \
	'<key>CFBundleVersion</key>' \
	'<string>1.0</string>' \
	'<key>CFBundleShortVersionString</key>' \
	'<string>1.0</string>' \
	'</dict>' \
	'</plist>' \
	> GetOffMyLawn.app/Contents/Info.plist

	codesign --force --deep --sign - GetOffMyLawn.app

package: app
	rm -f GetOffMyLawn.zip
	zip -r GetOffMyLawn.zip GetOffMyLawn.app

debug: build
	lldb GetOffMyLawn

clean:
	rm -rf GetOffMyLawn GetOffMyLawn.app GetOffMyLawn.zip
