#pragma once
#include <string>
#include <unordered_map>
#include "../vendor/glm/glm.hpp"

namespace Gio::Rendering 
{
	struct ShaderProgramSource
	{
		std::string name;
		std::string vertexSource;
		std::string fragmentSource;
	};

	class Shader
	{
	private:
		std::string _name;
		unsigned int _rendererID;
		std::unordered_map<std::string, int> _uniformLocationCache;
	
	public:
		Shader(ShaderProgramSource source);
		
		Shader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource);

		~Shader();

		void Bind() const;

		void UnBind() const;

		std::string GetName() { return _name; }

		unsigned int GetRendererID() {return _rendererID;}
		
		template <typename TUniform>
		void SetUniform(const std::string& name, TUniform val);

		template <typename TUniform>
        void SetUniformByLocation(int location, TUniform val);
		
		int GetUniformLocation(const std::string& name);

	private:
		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

		unsigned int CompileShader(unsigned int type, const std::string& source);
	};

	template <typename TUniform>
	void Shader::SetUniform(const std::string& name, TUniform val)
	{
		SetUniformByLocation(GetUniformLocation(name), val);
	}

}
