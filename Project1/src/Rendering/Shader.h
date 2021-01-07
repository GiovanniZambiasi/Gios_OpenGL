#pragma once
#include <string>
#include <unordered_map>

namespace Gio::Rendering 
{
	struct ShaderProgramSource
	{
		std::string vertexSource;
		std::string fragmentSource;
	};

	class Shader
	{
	private:
		std::string _filePath;
		unsigned int _rendererID;
		std::unordered_map<std::string, int> _uniformLocationCache;

	public:
		Shader(const std::string& filePath);

		~Shader();

		void Bind() const;

		void UnBind() const;

		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

		void SetUniform1f(const std::string& name, float v0);

	private:
		ShaderProgramSource ParseShader(const std::string& filePath);

		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

		unsigned int CompileShader(unsigned int type, const std::string& source);

		int GetUniformLocation(const std::string& name);
	};
}