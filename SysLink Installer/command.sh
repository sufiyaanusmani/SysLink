for file in /syslink/command/*.cpp
do
	g++ "$file" -o "${file%.cpp}"
done