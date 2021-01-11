#pragma once
#include <string>
#include <unordered_map>
#include "../vendor/glm/fwd.hpp"

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

		void SetUniformMat4f(const std::string& name, glm::mat4 matrix);

	private:
		ShaderProgramSource ParseShader(const std::string& filePath);

		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

		unsigned int CompileShader(unsigned int type, const std::string& source);

		int GetUniformLocation(const std::string& name);
	};
}
