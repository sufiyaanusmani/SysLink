for file in /syslink/realtime/*.cpp
do
	g++ "$file" -o "${file%.cpp}"
done