import 'package:flutter_test/flutter_test.dart';
import 'package:mockito/mockito.dart';
import 'package:dio/dio.dart';

import 'package:app_mobile/app/modules/home/cidades/interfaces/cidades_repository_interface.dart';

class MockClient extends Mock implements Dio {}

void main() {
  ICidadesRepository repository;
  // MockClient client;

  setUp(() {
    // client = MockClient();
    // repository = CidadesRepository(client);
  });

  group('CidadesRepository Test', () {
    //  test("First Test", () {
    //    expect(repository, isInstanceOf<CidadesRepository>());
    //  });

    test('returns a Post if the http call completes successfully', () async {
      //    when(client.get('https://jsonplaceholder.typicode.com/posts/1'))
      //        .thenAnswer((_) async =>
      //            Response(data: {'title': 'Test'}, statusCode: 200));
      //    Map<String, dynamic> data = await repository.fetchPost(client);
      //    expect(data['title'], 'Test');
    });
  });
}
