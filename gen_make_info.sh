#!/bin/zsh
current_path=`pwd`
[ -e CMakeLists.txt ] && rm -rf CMakeLists.txt;
for dir in `ls|grep -v cmake-build-debug`;do
	tmp=1
	if [ -d $dir ]; then
		for cpp_file in `ls $dir`;do
			echo "add_executable($dir$((tmp++)) $dir/$cpp_file)" >> CMakeLists.txt
		done
	elif [  "${dir##*.}" = "cpp" ]; then
		echo "add_executable(${dir%.*} $dir)" >> CMakeLists.txt
	fi
		#statements
done


