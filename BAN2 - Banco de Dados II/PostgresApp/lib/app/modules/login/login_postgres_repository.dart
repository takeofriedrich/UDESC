import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/login/excptions/usuario_nao_encontrado_excption.dart';
import 'package:app_mobile/app/modules/login/interfaces/login_repository_interface.dart';
import 'package:app_mobile/app/modules/login/models/usuario.dart';
import 'package:database/sql.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:postgres/postgres.dart';

part 'login_postgres_repository.g.dart';

@Injectable()
class LoginPostgresRepository extends ILoginRepository {
  PostgreSQLConnection connection = Modular.get<AppController>().connection;

  @override
  Future<Usuario> realizarLogin(String usuario, String senha) async {
    SqlClient client = Modular.get<AppController>().config;
    if (connection.isClosed) {
      await connection.open();
    }

    return Modular.get<AppController>().connection.query(
        'select * from realizarLogin(@usuario,@senha)',
        substitutionValues: {'usuario': usuario, 'senha': senha}).then((value) {
      return value.isNotEmpty
          ? Usuario.fromMap(value.first.toColumnMap())
          : throw UsuarioNaoEncontradoException();
    });
  }

  @override
  void dispose() {}
}
