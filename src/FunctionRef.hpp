#ifndef FUNCTION_REF_HPP
#define FUNCTION_REF_HPP
#include <utility>

template <typename Fn> class FunctionRef;

template <typename ReturnType, typename... Arguments>
class FunctionRef<ReturnType(Arguments...)> final {
public:
  template <typename FunctionType>
  FunctionRef(FunctionType &&function) noexcept
      : function(reinterpret_cast<void *>(&function)),
        executor(templateExecutor<
                 typename std::remove_reference<FunctionType>::type>) {}

  ReturnType operator()(Arguments... args) const {
    return executor(function, std::forward<Arguments>(args)...);
  }

private:
  void *function;
  ReturnType (*executor)(void *callable, Arguments... params);

  template <typename FunctionType>
  static ReturnType templateExecutor(void *function, Arguments... params) {
    return (*reinterpret_cast<FunctionType *>(function))(
        std::forward<Arguments>(params)...);
  }
};

#endif