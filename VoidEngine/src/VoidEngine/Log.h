#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace VoidEngine {
	class VOID_API Log
	{
	public:
		Log();
		~Log();

		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log Macros
#define VD_CORE_TRACE(...)   ::VoidEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VD_CORE_INFO(...)    ::VoidEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VD_CORE_WARN(...)    ::VoidEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VD_CORE_ERROR(...)   ::VoidEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VD_CORE_FATAL(...)   ::VoidEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)


// Client Log Macros
#define VD_TRACE(...)		 ::VoidEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VD_INFO(...)		 ::VoidEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define VD_WARN(...)		 ::VoidEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VD_ERROR(...)		 ::VoidEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define VD_FATAL(...)		 ::VoidEngine::Log::GetClientLogger()->critical(__VA_ARGS__)

