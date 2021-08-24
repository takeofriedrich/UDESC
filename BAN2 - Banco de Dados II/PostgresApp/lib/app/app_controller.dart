import 'package:app_mobile/app/modules/login/models/usuario.dart';
import 'package:database/sql.dart';
import 'package:database_adapter_postgre/database_adapter_postgre.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:postgres/postgres.dart';
part 'app_controller.g.dart';

@Injectable()
class AppController = _AppControllerBase with _$AppController;

abstract class _AppControllerBase with Store {
  PostgreSQLConnection connection = PostgreSQLConnection(
      '10.0.2.2', 5432, 'trabBan',
      username: 'postgres', password: 'XXXXX');
  SqlClient config = Postgre(
    host: '10.0.2.2',
    port: 5432,
    user: 'postgres',
    password: 'XXXXX',
    databaseName: 'trabBan',
  ).database().sqlClient;
  Usuario usuario;
}
