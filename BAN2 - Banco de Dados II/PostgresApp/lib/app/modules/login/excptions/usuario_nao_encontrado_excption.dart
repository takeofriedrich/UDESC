class UsuarioNaoEncontradoException implements Exception {
  @override
  String toString() {
    return 'Usuário não cadastrado!';
  }
}
