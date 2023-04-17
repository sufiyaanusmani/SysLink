for file in /syslink/realtime/*.cpp
do
	g++ "$file" -o "${file%.cpp}.syslink"
done