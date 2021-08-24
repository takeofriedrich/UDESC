import 'package:app_mobile/app/app_controller.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:postgres/postgres.dart';

import 'assentos_repository_interface.dart';

part 'assentos_postgres_repository.g.dart';

@Injectable()
class AssentosPostgresRepository implements IAssentosRepository {
  PostgreSQLConnection connection = Modular.get<AppController>().connection;
  final String selectAssentos =
      'select * from buscarAssentosTrecho(@codt) order by coda_;';
  final String sqlReservarAssento =
      'select * from realizarReserva(@codaP,@codpP,@dataP)';

  @override
  void dispose() {}

  @override
  Future<Map<int, bool>> listarAssentos(int codT) async {
    Map<int, bool> assentos = {};
    PostgreSQLResult resul = await connection
        .query(selectAssentos, substitutionValues: {'codt': codT});
    for (PostgreSQLResultRow row in resul) {
      Map<String, dynamic> json = row.toColumnMap();
      assentos[json['coda_']] = json['reservado_'];
    }
    return assentos;
  }

  @override
  Future<void> reservarAssento(int coda) async {
    return await connection.execute(sqlReservarAssento, substitutionValues: {
      'codaP': coda,
      'codpP': Modular.get<AppController>().usuario.codp,
      'dataP': DateTime.now()
    });
  }
}
