for file in /syslink/network/*.cpp
do
	g++ "$file" -o "${file%.cpp}.syslink"
done