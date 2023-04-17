for file in /syslink/sysinfo/*.cpp
do
	g++ "$file" -o "${file%.cpp}.syslink"
done